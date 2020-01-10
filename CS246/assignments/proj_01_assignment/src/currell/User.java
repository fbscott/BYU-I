package currell;

public class User {

    // private: field is accessible only w/in its own class
    private String password;
    private String salt;
    private String hashedPassword;

    // Constructors use the name of the class and do NOT have a return type.
    // The compiler automatically provides a no-argument, default constructor
    // for any class without constructors: public User() {}
    // public: field is accessible from all classes
    public User(String password) {
        this.password = password;
    } // non-default constructor

    // "alt + insert" > Getters and Setters
    // getters
    public String getPassword() {
        return password;
    }
    public String getSalt() { return salt; }
    public String getHashedPassword() {
        return hashedPassword;
    }

    // setters
    public void setPassword(String password) { this.password = password; }
    public void setSalt(String salt) {
        this.salt = salt;
    }
    public void setHashedPassword(String hashedPassword) {
        this.hashedPassword = hashedPassword;
    }

    // override stream operators
    // "alt + insert" > toString()
    @Override
    public String toString() {
        return "User{" +
                "password='" + password + '\'' +
                ", hashedPassword='" + hashedPassword + '\'' +
                ", salt='" + salt + '\'' +
                '}';
    }
}
