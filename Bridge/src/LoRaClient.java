import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.WebSocket;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.CompletionStage;

public class LoRaClient implements WebSocket.Listener {
    private static String cell1 = "0004A30B00251542";
    private static String cell2 = "0004A30B00251001";
    String hexTemp, hexHum, hexCo2;
    int decHum, decCo2;
    float decTemp;
    String cell;


    Adapter adapter = new Adapter();

    public LoRaClient() {
        HttpClient client = HttpClient.newHttpClient();
        CompletableFuture<WebSocket> ws = client.newWebSocketBuilder()
                .buildAsync(URI.create("wss://iotnet.teracom.dk/app?token=vnoSZQAAABFpb3RuZXQudGVyYWNvbS5kazos1kHsEnNwDTNgUNLnR-8="), this);
        hexTemp = "";
        hexHum = "";
        hexCo2 = "";
        decTemp = 0;
        decHum = 0;
        decCo2 = 0;

    }

    //onOpen()
    public void onOpen(WebSocket webSocket) {
        // This WebSocket will invoke onText, onBinary, onPing, onPong or onClose methods on the associated listener (i.e. receive methods) up to n more times
        webSocket.request(1);
        System.out.println("WebSocket Listener has been opened for requests.");
    }

    //onError()
    public void onError​(WebSocket webSocket, Throwable error) {
        System.out.println("A " + error.getCause() + " exception was thrown.");
        System.out.println("Message: " + error.getLocalizedMessage());
        webSocket.abort();
    }

    //onClose()
    public CompletionStage<?> onClose(WebSocket webSocket, int statusCode, String reason) {
        System.out.println("WebSocket closed!");
        System.out.println("Status:" + statusCode + " Reason: " + reason);
        return null;//new CompletableFuture().completedFuture("onClose() completed.").thenAccept(System.out::println);
    }

    //onPing()
    public CompletionStage<?> onPing​(WebSocket webSocket, ByteBuffer message) {
        webSocket.request(1);
        System.out.println("Ping: Client ---> Server");
        System.out.println(message.asCharBuffer().toString());
        return null;//new CompletableFuture().completedFuture("Ping completed.").thenAccept(System.out::println);
    }

    //onPong()
    public CompletionStage<?> onPong​(WebSocket webSocket, ByteBuffer message) {
        webSocket.request(1);
        System.out.println("Pong: Client ---> Server");
        System.out.println(message.asCharBuffer().toString());
        return null;//new CompletableFuture().completedFuture("Pong completed.").thenAccept(System.out::println);
    }

    //onText()
    public CompletionStage<?> onText​(WebSocket webSocket, CharSequence data, boolean last) {
            //System.out.println(data);
            getData(data.toString());
            webSocket.request(1);
            return null; //new CompletableFuture().completedFuture("onText() completed.").thenAccept(System.out::println);

    }

    private void getData(String json) {
        String findBy = "data";
        String deviceId = "EUI";
        String rx = "rx";
        ArrayList<String> list = new ArrayList<>(Arrays.asList(json.split(",")));
        if(rx.equals(list.get(0).substring(8,10))){
        for (int i = 0; i < list.size(); i++) {

                if ((list.get(i).contains(deviceId))) {
                    if (cell1.equals(list.get(i).substring(7, 23))) {
                        cell = "cell1";
                    } else if (cell2.equals(list.get(i).substring(7, 23))) {
                        cell = "cell2";
                    }


                }
                if (list.get(i).contains(findBy)) {
                    hexHum = list.get(i).substring(8, 12);
                    decHum = Integer.parseInt(hexHum, 16);
                    hexTemp = list.get(i).substring(12, 16);
                    decTemp = Integer.parseInt(hexTemp, 16);
                    hexCo2 = list.get(i).substring(16, 20);
                    decCo2 = Integer.parseInt(hexCo2, 16);

                    Adapter.getConnection();
                    adapter.add(decTemp / 10, decHum / 10, decCo2, cell);
                    System.out.println(cell + "\nTemperature: " + decTemp / 10 + "\nHumidity: " + decHum / 10 + "%\nCO2: " + decCo2);

                }


            }
        }
    }
}
