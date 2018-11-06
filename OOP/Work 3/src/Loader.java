import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

public final class Loader {
    public static Path getFilePath(String filename) throws URISyntaxException {
        return Paths.get(ClassLoader.getSystemResource(filename).toURI());
    }

    @NotNull
    public static String getFileContent(Path path) {

        StringBuilder fileContent = new StringBuilder();
        try (Stream<String> lines = Files.lines(path)) {
            lines.forEach(line -> fileContent.append(line).append("\n"));
        } catch (IOException exception) {
            System.err.println("Failed to read file " + path);
            exception.printStackTrace();
        }

        return fileContent.toString();
    }

    @NotNull
    public static String getFileContent(String filename) throws URISyntaxException {
        return Loader.getFileContent(Loader.getFilePath(filename));
    }

}
