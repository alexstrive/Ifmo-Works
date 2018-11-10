package io.github.novopashin.dao.strategies.general;

public class Targetable {
    private Object targetObject;

    public Targetable(Object targetObject) {
        this.targetObject = targetObject;
    }

    protected Object getTargetObject() {
        return targetObject;
    }
}
