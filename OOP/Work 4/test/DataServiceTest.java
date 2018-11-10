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
     *
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
     *
     * Создать товар
     */
    @Test
    void task2() {
        var productTitle = "Test Product Title";
        var vendorCode = 1001;
        var quantity = 6572;
        var cost = 32;
        assert false;
    }

    /**
     * Задание 3
     *
     * Завезти партию товаров в магазин (набор товар-количество с возможностью
     * установить/изменить цену)
     */
    @Test
    void task3() {
        assert false;
    }

    /**
     * Задание 4
     *
     * Найти магазин, в котором определенный товар самый дешевый
     */
    @Test
    void task4() {
        assert false;
    }

    /**
     * Задание 5
     *
     * Понять, какие товары можно купить в магазине на некоторую сумму (например, на
     * 100 рублей можно купить три мороженки или две шоколадки)
     */
    @Test
    void task5() {
        assert false;
    }

    /**
     * Задание 6
     *
     * Купить партию товаров в магазине (параметры - сколько каких товаров купить,
     * метод возвращает общую стоимость покупки либо её невозможность, если товара
     * не хватает)
     */
    @Test
    void task6() {
        assert false;
    }

    /**
     * Задание 7
     *
     * Найти, в каком магазине партия товаров (набор товар-количество) имеет
     * наименьшую сумму (в целом). Например, «в каком магазине дешевле всего купить 10 гвоздей и 20 шурупов». Наличие товара в магазинах учитывается!
     */
    @Test
    void task7() {
        assert false;
    }

    /**
     * Дополнительное задание
     *
     * В качестве дополнительного бонуса (и для удобства) можно написать скрипт (с отдельной точкой входа)
     * для преобразования данных из файлов в базу данных и обратно
     */
    @Test
    void fromCSVtoSQL() {
        assert false;
    }

    @Test
    void fromSQLtoCSV() {
        assert false;
    }
}
