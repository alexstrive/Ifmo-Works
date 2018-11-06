import java.text.ParseException;

public class Main {

    public static void main(String[] args) throws ParseException {
        try (var config = new ConfigFile("settings.ini")) {
            var stringValue = config.getAttribute("COMMON", "DiskCachePath", String.class);
            var doubleValue = config.getAttribute("ADC_DEV", "BufferLenSeconds", Double.class);
            var booleanValue = config.getAttribute("DEBUG", "SomeBoolVal", Boolean.class);

            var val = config.getAttribute("ADC_DEV", "BufferLenSeconds", Double.class);
            System.out.println(val + " has "  + val.getClass());

            System.out.println(stringValue + "has " + stringValue.getClass());
            System.out.println(doubleValue + "has " + doubleValue.getClass());
            System.out.println(booleanValue + "has " + booleanValue.getClass());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
