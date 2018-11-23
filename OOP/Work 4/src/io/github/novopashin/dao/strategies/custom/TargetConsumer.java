package io.github.novopashin.dao.strategies.custom;

public class TargetConsumer {
    private Object targetObject;

    public TargetConsumer(Object targetObject) {
        this.targetObject = targetObject;
    }

    protected Object getTargetObject() {
        return targetObject;
    }
}
