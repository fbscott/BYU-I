package currell;

import com.google.gson.Gson;

import java.util.Scanner;

public class Main {

    String url = "http://example.com";
    String charset = "UTF-8";  // Or in Java 7 and later, use the constant: java.nio.charset.StandardCharsets.UTF_8.name()
    String param1 = "value1";
    String param2 = "value2";

    /**
     * Test the readHTTP function.
     * @param args
     */
    public static void main(String[] args) {
        // new HTTPHelper instance assigned to a variable called "http"
        HTTPHelper http = new HTTPHelper();

        // build the url for the API call
        final String urlRootWeather = "http://api.openweathermap.org/data/2.5/weather";
        final String urlRootForecast = "http://api.openweathermap.org/data/2.5/forecast";
        final String apiKey = "efb3e20ecbe6d6d8220230bbafc45108";
        String city; // city placeholder

        System.out.println("Specify a U.S. city: ");

        Scanner userInput = new Scanner(System.in);

        city = userInput.nextLine(); // "nextLine" returns a string

        //****************************** Weather API ********************************
        // JSON returned by http.readHTTP
        // Example API call: http://api.openweathermap.org/data/2.5/weather?q=Rexburg,%20US,%20US&apiKey=efb3e20ecbe6d6d8220230bbafc45108
        String result = http.readHTTP(urlRootWeather + "?q=" + city + ",%20US,%20US" + "&units=imperial" + "&apiKey=" + apiKey);

        // print the JSON
        // System.out.println(result);

        Gson gson = new Gson();

        // deserialize the JSON (convert it into a Java object - specifically, WeatherConditions)
        WeatherConditions wc = gson.fromJson(result, WeatherConditions.class);

        // print the deserialized Java object
        // System.out.println(wc);

        //****************************** Forecast API ********************************
        // JSON returned by http.readHTTP
        // Example API call: http://api.openweathermap.org/data/2.5/weather?q=Rexburg,%20US,%20US&apiKey=efb3e20ecbe6d6d8220230bbafc45108
        result = http.readHTTP(urlRootForecast + "?q=" + city + ",%20US,%20US" + "&units=imperial" + "&apiKey=" + apiKey);

        // print the JSON
        // System.out.println(result);

        gson = new Gson();

        // deserialize the JSON (convert it into a Java object - specifically, WeatherForecast)
        WeatherForecast wf = gson.fromJson(result, WeatherForecast.class);

        // print the deserialized Java object
        System.out.println(wf);
    } // end main()

}
