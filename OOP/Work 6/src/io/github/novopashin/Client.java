package io.github.novopashin;

public class Client {
    private String firstName, lastName;
    private String address, passport;

    private Client(String firstName, String lastName, String address, String passport) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.address = address;
        this.passport = passport;
    }

    public boolean isShady() {
        return this.address == null || this.passport == null;
    }

    public static class Builder {
        // required
        private String firstName, lastName;
        // optional
        private String address, passport;

        public Client create() throws Exception {
            // Check presence of name
            if (this.firstName == null && this.lastName == null) {
                throw new Exception("Необходимо указать имя и фамилию перед созданием клиента");
            }

            return new Client(firstName, lastName, address, passport);
        }

        public Builder name(String firstName, String lastName) {
            this.firstName = firstName;
            this.lastName = lastName;

            return this;
        }

        public Builder address(String address) {
            this.address = address;

            return this;
        }

        public Builder passport(String passport) {
            this.passport = passport;

            return this;
        }
    }
}
