package io.github.novopashin.dao.strategies.custom.store;

import io.github.novopashin.dao.strategies.custom.TargetConsumerSQL;
import io.github.novopashin.dao.strategies.general.CreateStrategy;

import java.util.Map;

public class CreateStoreSQL extends TargetConsumerSQL implements CreateStrategy {
    public CreateStoreSQL(String tablename, String host, String login, String password) {
        super(tablename, host, login, password);
    }

    @Override
    public void execute(Map payload) {
        var title = payload.get("title");
        update("insert into " + getTablename() + " values ('" + title + "')");
    }
}
