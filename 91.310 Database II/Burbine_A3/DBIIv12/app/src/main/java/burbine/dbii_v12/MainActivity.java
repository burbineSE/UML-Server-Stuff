package burbine.dbii_v12;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.net.wifi.WifiManager;
import android.content.Context;
import java.nio.ByteOrder;
import java.math.BigInteger;
import java.net.InetAddress;
import java.net.UnknownHostException;
import android.util.Log;

public class MainActivity extends Activity {
	
	private WebView mWebView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		mWebView = (WebView) findViewById(R.id.webview);
		mWebView.getSettings().setJavaScriptEnabled(true);

        //test webview
		//mWebView.loadUrl("http://www.google.com");

        //emulator webview
		//mWebView.loadUrl("http://10.0.2.2/DBII_A2_v1/");

        //tablet webview; home
        mWebView.loadUrl("http://192.168.1.8/DBII_A2_v1/");

        //tablet webview; school
        //mWebView.loadUrl("http://10.253.73.26/DBII_A2_v1/");

        //am attempt at a modular IP finder, returns the default
        //gateway IP value but not the IPv4 value, which is what
        //the webview seems to need
        //String ipAddress = wifiIpAddress();
        //mWebView.loadUrl("http://"+ ipAddress +"/DBII_A2_v1/");

        mWebView.setWebViewClient(new DBIIWebViewClient());
	}
	
	private class DBIIWebViewClient extends WebViewClient {
		@Override
		public boolean shouldOverrideUrlLoading(WebView webview, String url){
			webview.loadUrl(url);
			return true;
		}

	}
	
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event){
		if ((keyCode == KeyEvent.KEYCODE_B) && mWebView.canGoBack()){
			mWebView.goBack();
			return true;
		}
		return super.onKeyDown(keyCode, event);
	}

    //found at (http://stackoverflow.com/questions/16730711/get-my-wifi-ip-address-android)
    protected String wifiIpAddress() {
        WifiManager wifiManager = (WifiManager) getSystemService(Context.WIFI_SERVICE);
        int ipAddress = wifiManager.getConnectionInfo().getIpAddress();

        // Convert little-endian to big-endianif needed
        if (ByteOrder.nativeOrder().equals(ByteOrder.LITTLE_ENDIAN)) {
            ipAddress = Integer.reverseBytes(ipAddress);
        }

        byte[] ipByteArray = BigInteger.valueOf(ipAddress).toByteArray();

        String ipAddressString;
        try {
            ipAddressString = InetAddress.getByAddress(ipByteArray).getHostAddress();
        } catch (UnknownHostException ex) {
            Log.e("WIFIIP", "Unable to get host address.");
            ipAddressString = null;
        }

        return ipAddressString;
    }
}
