package currell;

import com.google.gson.annotations.SerializedName;

import java.util.List;
import java.util.Map;

public class WeatherForecast {

    @SerializedName("list")
    private List<WeatherForecastItem> items;
//    private Map<String, String> city;

//    public List<WeatherForecastItem> getItems() {
//        return items;
//    }

    @Override
    public String toString() {
        return "Weather Forecast:\n" + items;
    }
}
