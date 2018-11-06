import org.jetbrains.annotations.NotNull;

import java.net.URISyntaxException;
import java.text.NumberFormat;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ConfigFile implements AutoCloseable{
    private HashMap<String, HashMap<String, String>> sections = new HashMap<>();

    public ConfigFile(String filename) {
        if (!filename.contains(".ini")) {
            throw new Error("Illegal file extension");
        }

        try {
            Loader.getFileContent(filename)
                    .lines()
                    .forEach(this::convertToNode);
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }
    }

    private Pattern sectionPattern = Pattern.compile("^\\[(?<name>\\w+)]$");
    private Pattern attributePattern = Pattern.compile("^(?<name>[A-Za-z]+)\\s=\\s(?<value>[\\w/.]+).*$");
    private Pattern skipPattern = Pattern.compile("(^$|^;.*$)");
    private String currentSectionName;

    private void convertToNode(String nodeString) {
        var isSection = sectionPattern.asPredicate();
        var isAttribute = attributePattern.asPredicate();
        var ableToSkip = skipPattern.asPredicate();

        if (ableToSkip.test(nodeString)) {
            return;
        }

        if (isSection.test(nodeString)) {
            var matcher = completedMatcher(sectionPattern, nodeString);
            var sectionName = matcher.group("name");
            sections.put(sectionName, new HashMap<>());
            currentSectionName = sectionName;
            return;
        }

        if (isAttribute.test(nodeString)) {
            var matcher = completedMatcher(attributePattern, nodeString);
            var attributeName = matcher.group("name");
            var attributeValue = matcher.group("value");
            this.sections.get(currentSectionName).put(attributeName, attributeValue);
            return;
        }

        throw new Error("Illegal syntax");
    }

    private Matcher completedMatcher(@NotNull Pattern pattern, String input) {
        var matcher = pattern.matcher(input);
        matcher.matches();
        return matcher;
    }

    private HashMap<String, String> getSection(String sectionName) throws Exception {

        if (!this.sections.containsKey(sectionName)) {
            throw new Exception("No such section name");
        }

        return (HashMap<String, String>) this.sections.get(sectionName).clone();
    }

    public <T> T getAttribute(String sectionName, String attributeName, Class<T> clazz) throws Exception {
        var gottenValue = this.getSection(sectionName).get(attributeName);

        if (clazz.isAssignableFrom(String.class)) {
            return (T) gottenValue;
        }

        if (clazz.isAssignableFrom(Integer.class)) {
            return (T) Integer.valueOf(gottenValue);
        }

        if (clazz.isAssignableFrom(Double.class)) {
            return (T) Double.valueOf(gottenValue);
        }

        if (clazz.isAssignableFrom(Boolean.class)) {
            return (T) Boolean.valueOf(gottenValue);
        }

        throw new Exception("Illegal class type passed");
    }


    @Override
    public void close() throws Exception { }
}