import io.github.novopashin.Client;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class ClientTest {

    @Test
    @DisplayName("Создания экземпляра клиента с помощью строителя")
    void createExampleClient() throws Exception {
        var clientBuilder = new Client.Builder();

        var exampleClient = clientBuilder
                .name("Alexey", "Novopashin")
                .create();
    }

    @Test
    @DisplayName("Появление ошибки при создании экземпляра без указания имени и фамилии")
    void createClientWithException() throws Exception {
        var clientBuilder = new Client.Builder();

        assertThrows(Exception.class, () -> {
            var illegalClient = clientBuilder.
                    create();
        });
    }

    @Test
    @DisplayName("Создание \"сомнительного\" клиента")
    void createShadyClient() throws Exception {
        var clientBuilder = new Client.Builder();
        var client = clientBuilder
                .name("Alexey", "Novopashin")
                .create();

        assertTrue(client.isShady());
    }
}
