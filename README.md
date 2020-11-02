# CPP-Example
This is the example code for C++.

I will not be including the .lib as that is a paid resource.


# Usage
Response is a class that contains data such as license, expiry, etc. and myauth::authenticate returns a instance of that with license data.
It takes two inputs License, and Public Key.
And you can verify like so
```cpp
  auto response = myauth::authenticate(key, PUBLIC_KEY);

  if (response->Error == success) 
  {
    if (myauth::verify_integrity()) 
    {
        // verified
    }
  }
  ```


# Cons and Pros
Pros | Cons
------------ |-----
Very clean  | Not open-source.
Easy usage | Not using JSON
