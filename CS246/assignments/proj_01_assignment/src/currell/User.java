package currell;

public class User {

    private String password;
    private String hashedPassword;
    private String salt;

    // constructor
    public User(String password) {
        this.password = password;
    }

    // "alt + insert" > Getters and Setters
    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getHashedPassword() {
        return hashedPassword;
    }

    public void setHashedPassword(String hashedPassword) {
        this.hashedPassword = hashedPassword;
    }

    public String getSalt() {
        return salt;
    }

    public void setSalt(String salt) {
        this.salt = salt;
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
