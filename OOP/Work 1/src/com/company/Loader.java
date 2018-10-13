package com.company;

import java.nio.file.Path;
import java.nio.file.Paths;

public interface Loader {
    public static Path getFilePath(String fileName) {
        return Paths.get(NumberList.class.getClassLoader().getResource(fileName).getFile());
    }
}
