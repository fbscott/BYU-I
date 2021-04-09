package currell;

import com.google.gson.annotations.SerializedName;

import java.util.Map;

public class WeatherConditions {

    private int id;
    private String name;

    // Annotation: Tells GSON to match the "main" key to the next
    // declared member variable in this class: "measurements" in this case.
    @SerializedName("main")
    private Map<String, Float> measurements;

    @Override
    public String toString() {
        return "WeatherConditions{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", measurements=" + measurements +
                '}';
    }
}
