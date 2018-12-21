package io.github.novopashin;

import io.github.novopashin.annotations.XmlAttribute;
import io.github.novopashin.annotations.XmlObject;
import io.github.novopashin.annotations.XmlTag;

import java.io.Serializable;

@XmlObject
public class Person implements Serializable {
    @XmlTag(name = "fullname")
    private final String name;

    @XmlAttribute(tag = "fullname")
    private final String lang;

    private final int age;

    public Person(String name, String lang, int age) {
        this.name = name;
        this.lang = lang;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    @XmlTag(name = "age")
    public int getAge() {
        return age;
    }

    @XmlTag
    public final ChildPerson childPerson = new ChildPerson();
}