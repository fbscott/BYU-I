package currell;

import com.google.gson.annotations.SerializedName;

import java.util.List;
import java.util.Map;

public class WeatherForecastItem {

    // Annotation: Tells GSON to match the "dt_tx" key to the next
    // declared member variable in this class: "time" in this case.
    @SerializedName("dt_txt")
    private String time;

    // Annotation: Tells GSON to match the "main" key to the next
    // declared member variable in this class: "measurements" in this case.
    @SerializedName("main")
    private Temperature temperature;

    private WeatherWind wind;

    @SerializedName("weather")
    private List<WeatherDescription> description;

//    public String getTime() {
//        return time;
//    }
//
//    public Map getMeasurements() {
//        return measurements;
//    }

    @Override
    public String toString() {
        return " - Time: " + time + ',' +
               temperature + ',' +
               " - Weather Conditions: " + description.get(0) + ',' +
               " - Wind Speed: " + wind + '\n';
    }
}
