package io.github.novopashin.dao.strategies.custom.product;

import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVPrinter;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URISyntaxException;

public class CreateProductCSV extends CreateProduct {
    public CreateProductCSV(Object filename) {
        super(filename);
    }

    private String getFilename() {
        return getTargetObject().toString();
    }

    @Override
    public void execute(Object... values) {
        var title = values[0];
        var vendor = values[1];
        var quantity = values[2];
        var cost = values[3];

        try (var writerCSV = new CSVPrinter(new FileWriter(
                new File(ClassLoader.getSystemResource(getFilename()).toURI()), true), CSVFormat.DEFAULT)) {
            writerCSV.printRecord(title, vendor, quantity, cost);
        } catch (URISyntaxException | IOException e) {
            e.printStackTrace();
        }
    }
}
