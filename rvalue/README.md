## rvalue lvalue and move

###  Definitions
 - an **Lvalue** denotes an object whose **resource cannot be reused**, which includes most objects that we can think of in code. Lvalues include expressions that designate objects directly by their names but not only.
 - an **Rvalue** denotes an object whose **resource can be reused**, that is to say a **disposable object**. This typically includes temporary objects as they can�t be manipulated at the place they are created and are soon to be destroyed.
 - an **Lvalue** reference is a reference that binds to an **Lvalue**
 - an **Rvalue** reference is a reference that binds to an **Rvalue**
 - there can be **Lvalue const** reference binding to an **Rvalue**


```cpp
    int x = 123; // literal "123" is an Rvalue that must be stored into a Lvalue (x)
    std::string s1 = "Hello ";
    std::string s2 = "World ";
    std::string s3 = s1 + s2; // create a temporary object result of + so an Rvalue that must be stored in a Lvalue (s3)
    int& x = 123;       // Error
    const int& x = 123; // OK: Lvalue const bound to Rvalue
```


## References
1. https://www.fluentcpp.com/2018/02/06/understanding-lvalues-rvalues-and-their-references/
