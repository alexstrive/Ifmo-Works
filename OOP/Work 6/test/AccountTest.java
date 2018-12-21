import io.github.novopashin.AccountFactory;
import io.github.novopashin.Client;
import io.github.novopashin.account.Account;
import io.github.novopashin.requests.ChargePercentageRequest;
import io.github.novopashin.requests.CommissionPercentageRequest;
import io.github.novopashin.requests.Request;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class AccountTest {
    private AccountFactory alexAccounts, bobAccounts, shadyAccounts;

    @BeforeEach
    public void createNewClient() throws Exception {
        var clientBuilder = new Client.Builder();
        var alexClient = clientBuilder
                .name("Alexey", "Novopashin")
                .passport("1234 567890")
                .address("Spb")
                .create();

        this.alexAccounts = new AccountFactory(alexClient);

        var bobClient = clientBuilder
                .name("Bob", "Smn")
                .passport("3214 12452434")
                .address("Spb")
                .create();

        this.bobAccounts = new AccountFactory(bobClient);

        var shadyClient = clientBuilder
                .name("Shady", "Client")
                .create();

        this.shadyAccounts = new AccountFactory(shadyClient);
    }

    @Test
    @DisplayName("Пример работы с текущим счетом")
    public void currentAccountTest() throws Exception {
        var account = this.alexAccounts.create(Account.Type.CURRENT);

        account.deposit(400);
        account.deposit(1_000_00);
        account.withdraw(500);
//        account.withdraw(100_200_300);
    }

    @Test
    @DisplayName("Пример работы с депозитным счетом")
    public void depositAccountTest() throws Exception {
        var account = this.alexAccounts.create(Account.Type.DEPOSIT);

        account.deposit(400);
        account.deposit(1_000_000);
//        account.withdraw(500);
    }

    @Test
    @DisplayName("Пример работы с кредитным счетом")
    public void creditAccountTest() throws Exception {
        var account = this.alexAccounts.create(Account.Type.CREDIT);

        account.deposit(400);

        account.withdraw(100);
        account.withdraw(400);
        account.withdraw(400);
    }

    @Test
    @DisplayName("Перевод между счетами")
    public void transfer() throws Exception {
        var account = this.alexAccounts.create(Account.Type.CURRENT);
        var anotherAccount = this.alexAccounts.create(Account.Type.CURRENT);
        var bobAccount = this.bobAccounts.create(Account.Type.CURRENT);

        account.deposit(100);
        account.transfer(anotherAccount, 50);
//        account.transfer(bobAccount, 20);
    }

    @Test
    public void request() {
        var requestChain = new Request();

        requestChain
                .with(new ChargePercentageRequest(0.10))
                .with(new CommissionPercentageRequest(0.20))
                .with(new ChargePercentageRequest(0.12))
                .with(new ChargePercentageRequest(0.15));
        var account = this.alexAccounts.create(Account.Type.CURRENT);
        account.deposit(100);
        account.send(requestChain);
    }
}
