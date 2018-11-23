import io.github.novopashin.DataService;
import io.github.novopashin.Loader;

import io.github.novopashin.MigrationType;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.util.Properties;

import static org.junit.jupiter.api.Assertions.*;

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
     * <p>
     * Создать магазин
     */
    @Test
    void task1() {
        var title = "New Store 2";
        dataService.createStore(title);

        assertTrue(dataService.hasStore(title), "Содержит созданный магазин");
    }

    @Test
    void noGhostStore() {
        var title = "Ghost store";

        assertFalse(dataService.hasStore(title));
    }

    /**
     * Задание 2
     * <p>
     * Создать товар
     */
    @Test
    void task2() {
        var title = "Test Product Title";
        var vendor = 1001;
        var quantity = 6572;
        var cost = 32.23f;
        dataService.createProduct(title, vendor, quantity, cost);

        assertTrue(dataService.hasProduct(title));
    }

    @Test
    void noGhostProduct() {
        var title = "Ghost store";

        assertFalse(dataService.hasProduct(title));
    }

    /**
     * Задание 3
     * <p>
     * Завезти партию товаров в магазин (набор товар-количество с возможностью
     * установить/изменить цену)
     */
    @Test
    void task3() {
        dataService.shipProducts("Test Product Title", 1001, 123123, 923f);
    }

    /**
     * Задание 4
     * <p>
     * Найти магазин, в котором определенный товар самый дешевый
     */
    @Test
    void task4() {
        var productTitle = "Test Product Title";
        var mostCheapVendorProductCode = dataService.getMostCheapVendorOfProduct(productTitle);
        System.out.println("Самые дешевые поставщики продукта `" + productTitle + "`: " + mostCheapVendorProductCode);
    }

    /**
     * Задание 5
     * <p>
     * Понять, какие товары можно купить в магазине на некоторую сумму (например, на
     * 100 рублей можно купить три мороженки или две шоколадки)
     */
    @Test
    void task5() {
        var price = 20f;
        var possibilities = dataService.whichProductsPossibleBuy(price);
        System.out.println("За $" + price + " можно приобрести: ");
        possibilities.forEach((title, number) -> System.out.println("\t" + title + " " + number));
    }

    /**
     * Задание 6
     * <p>
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
     * <p>
     * Найти, в каком магазине партия товаров (набор товар-количество) имеет
     * наименьшую сумму (в целом). Например, «в каком магазине дешевле всего купить 10 гвоздей и 20 шурупов». Наличие товара в магазинах учитывается!
     */
    @Test
    void task7() {
        assert false;
    }

    /**
     * Дополнительное задание
     * <p>
     * В качестве дополнительного бонуса (и для удобства) можно написать скрипт (с отдельной точкой входа)
     * для преобразования данных из файлов в базу данных и обратно
     */
    @Test
    @Disabled
    void fromCSVtoSQL() {
        dataService.migrate(MigrationType.CSV_TO_SQL);
    }

    @Test
    @Disabled
    void fromSQLtoCSV() {
        dataService.migrate(MigrationType.SQL_TO_CSV);
    }
}
