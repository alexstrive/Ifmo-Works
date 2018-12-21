package io.github.novopashin;

import io.github.novopashin.annotations.XmlAttribute;
import io.github.novopashin.annotations.XmlObject;
import io.github.novopashin.annotations.XmlTag;
import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.OutputFormat;
import org.dom4j.io.XMLWriter;

import java.io.FileOutputStream;

public class Main {

    static Document serialized(Object object) throws Exception {
        if (!object.getClass().isAnnotationPresent(XmlObject.class)) {
            throw new Exception("Illegal object passed (not annotated)");
        }

        var rootTag = object.getClass().getSimpleName();
        var document = DocumentHelper.createDocument();
        var root = document.addElement(rootTag);

        var fields = object.getClass().getDeclaredFields();
        var methods = object.getClass().getDeclaredMethods();

        for (var field : fields) {
            if (field.isAnnotationPresent(XmlTag.class)) {
                field.setAccessible(true);

                if (field.get(object).getClass().isAnnotationPresent(XmlObject.class)) {
                    var serializedElement = serialized(field.get(object)).getRootElement();
                    root.add(serializedElement);
                    continue;
                }

                var tagname = (field.getAnnotation(XmlTag.class)).name();

                if (tagname.equals("UNDEFINED")) {
                    root.addElement(field.getName()).addText(field.get(object).toString());
                    continue;
                }

                root.addElement(tagname).addText(field.get(object).toString());
            }
        }

        for (var method : methods) {
            if (method.isAnnotationPresent(XmlTag.class)) {
                method.setAccessible(true);
                var tagname = (method.getAnnotation(XmlTag.class)).name();

                if (tagname.equals("UNDEFINED")) {
                    root.addElement(method.getName()).addText(method.invoke(object).toString());
                    continue;
                }

                root.addElement(tagname).addText(method.invoke(object).toString());
            }
        }

        for (var field : fields) {
            if (field.isAnnotationPresent(XmlAttribute.class)) {
                field.setAccessible(true);
                var tagname = (field.getAnnotation(XmlAttribute.class)).tag();

                if (tagname.equals("UNDEFINED")) {
                    root.addAttribute(field.getName(), field.get(object).toString());
                    continue;
                }


                var node = (Element) document.selectSingleNode("//" + tagname);
                node.addAttribute(field.getName(), field.get(object).toString());
            }
        }

        for (var method : methods) {
            if (method.isAnnotationPresent(XmlAttribute.class)) {
                method.setAccessible(true);
                var tagname = (method.getAnnotation(XmlAttribute.class)).tag();

                if (tagname.equals("UNDEFINED")) {
                    root.addAttribute(method.getName(), method.invoke(object).toString());
                    continue;
                }

                if (method.getReturnType() == Void.class) {
                    throw new Exception("Impossible to serialize. Method returns void.");
                }

                if (method.getParameterCount() > 0) {
                    throw new Exception("Impossible to serialize. Method has arguments.");
                }

                var node = (Element) document.selectSingleNode("//" + tagname);
                node.addAttribute(method.getName(), method.invoke(object).toString());
            }
        }

        return document;
    }

    public static void main(String[] args) throws Exception {
        var person = new Person("Sergey", "RUS", 32);
        var serializedPerson = serialized(person);

        OutputFormat format = OutputFormat.createPrettyPrint();
        var outputStream = new FileOutputStream("output.xml");
        var writer = new XMLWriter(outputStream, format);
        writer.write(serializedPerson);
    }
}
