package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.Loader;
import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVPrinter;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URISyntaxException;

public class CreateStoreCSV extends CreateStore {

    public CreateStoreCSV(String filename) {
        super(filename);
    }

    private int getFreeCodeVendor() {
        return Loader.getRecords(getTargetObject().toString()).size();
    }

    @Override
    public void execute(Object... values) {
        var codeVendor = getFreeCodeVendor();
        var storeTitle = values[0];

        try (var writerCSV = new CSVPrinter(new FileWriter(
                new File(ClassLoader.getSystemResource(getFilename()).toURI()), true), CSVFormat.DEFAULT)) {
            writerCSV.printRecord(codeVendor, storeTitle);
        } catch (URISyntaxException | IOException e) {
            e.printStackTrace();
        }
    }


}
