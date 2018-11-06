package dao;

abstract class DAOImplementation {
    abstract void createTable(String title);
    abstract boolean hasTable(String title);
}
