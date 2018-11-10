import io.github.novopashin.DataService;
import io.github.novopashin.Loader;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.util.Properties;

class DataServiceTest {
    private DataService dataService;

    @BeforeEach
    void prepare() throws IOException {
        var properties = new Properties();
        properties.load(Loader.getFileContentStream("config.properties"));
        dataService = new DataService(properties);
    }


    /**
     * Задание 1
     * Создать магазин
     */
    @Test
    void task1() {
        var storeTitle = "New Store";
        dataService.createStore(storeTitle);
        assertTrue(dataService.hasStore(storeTitle), "Содержит созданный магазин");
    }

    /**
     * Задание 2
     * Создать товар
     */
    @Test
    void task2() {

    }

}
