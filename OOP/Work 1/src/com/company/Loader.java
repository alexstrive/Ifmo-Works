package com.company;

import java.io.IOException;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Loader {
    public static Path getFilePath(String filename) throws URISyntaxException {
        return Paths.get(ClassLoader.getSystemResource(filename).toURI());
    }

    public static String getFileContent(Path path) {

        StringBuilder fileContent = new StringBuilder();
        try (Stream<String> lines = Files.lines(path)) {
            lines.forEach(line -> fileContent.append(line).append("\n"));
        } catch (IOException exception) {
            System.err.println("Failed to open file: " + path);
            exception.printStackTrace();
        }

        return fileContent.toString();
    }

    public static String getFileContent(String filename) throws URISyntaxException {
        return Loader.getFileContent(Loader.getFilePath(filename));
    }

    public static InputStream getFileContentStream(String filename) {
        return Loader.class.getClassLoader().getResourceAsStream(filename);
    }
}