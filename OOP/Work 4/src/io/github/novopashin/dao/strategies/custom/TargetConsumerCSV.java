package io.github.novopashin.dao.strategies.custom;

import io.github.novopashin.Loader;
import io.github.novopashin.dao.schemes.Scheme;
import io.github.novopashin.dao.schemes.SchemeType;
import io.github.novopashin.dao.strategies.general.FilterStrategy;
import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVPrinter;
import org.apache.commons.csv.CSVRecord;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Map;
import java.util.stream.Stream;

public abstract class TargetConsumerCSV extends TargetConsumer {
    private String[] mappings;

    public TargetConsumerCSV(String filename, String... mappings) {
        super(filename);
        this.mappings = mappings;
    }

    protected void writeCSV(Object... values) {
        try (var writerCSV = new CSVPrinter(new FileWriter(
                new File(ClassLoader.getSystemResource(getFilename()).toURI()), true), CSVFormat.DEFAULT)) {
            writerCSV.printRecord(values);
        } catch (URISyntaxException | IOException e) {
            e.printStackTrace();
        }
    }

    protected Stream<Map<String, String>> filteredStream(Map<String, String> targetValues) {
        var records = Loader.getRecords(getFilename(), this.mappings);

        return records.stream()
                .map(CSVRecord::toMap)
                .filter(currentValues -> FilterStrategy.isMapValueEqual(currentValues, targetValues));
    }

    private String getFilename() {
        return getTargetObject().toString();
    }
}
