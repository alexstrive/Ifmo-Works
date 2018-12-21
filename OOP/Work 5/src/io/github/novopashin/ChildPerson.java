package io.github.novopashin;

import io.github.novopashin.annotations.XmlObject;
import io.github.novopashin.annotations.XmlTag;

@XmlObject
public class ChildPerson {

    @XmlTag
    private String title = "test";
}
