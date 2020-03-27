package currell;

import com.google.gson.annotations.SerializedName;

import java.util.List;
import java.util.Map;

public class WeatherForecast {

    @SerializedName("list")
    private List<WeatherForecastItem> items;

//    Old code before looking at teacher solution
//    @Override
//    public String toString() {
//        return "Weather Forecast:\n" + items;
//    }

    public String toString() {
        StringBuilder result = new StringBuilder();

        for (WeatherForecastItem item : items) {
            result.append(item.toString() + "\n");
        }

        return result.toString();
    }
}
