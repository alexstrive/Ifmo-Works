import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

public final class Loader {
    public static Path getFilePath(String fileName) {
        return Paths.get(Loader.class.getClassLoader().getResource(fileName).getFile());
    }

    public static String getFileContent(Path path) {
        StringBuilder fileContent = new StringBuilder();
        try (Stream<String> lines = Files.lines(path)) {
            lines.forEach(fileContent::append);
        } catch (IOException exception) {
            System.err.println("[Error] Failed to read file " + path);
            exception.printStackTrace();
        } finally {
            System.out.println(fileContent);
        }
        return fileContent.toString();
    }
}
