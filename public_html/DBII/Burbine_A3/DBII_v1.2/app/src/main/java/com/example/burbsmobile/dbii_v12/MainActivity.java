package com.example.burbsmobile.dbii_v12;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import android.app.Activity;
import android.view.View;
import android.view.View.OnLongClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;


import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.w3c.dom.Text;


public class MainActivity extends ActionBarActivity {

    private Spinner spinner1;
    private Button button1;
    private Text text1;
    JSONArray jArray = null;
    String result = null;
    StringBuilder sb = null;
    InputStream is = null;

    //final TextView mnTextView = (TextView) findViewById(R.id.text);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //addListenerOnButton();
        addListenerOnSpinnerItemSelection();

        Spinner tableSpinner = (Spinner) findViewById(R.id.search_table);
        EditText nameText = (EditText) findViewById(R.id.search_for);

        String spinner_text = tableSpinner.getSelectedItem().toString();
        String edittext_text = nameText.getText().toString();

        //http://m-zeeshanarif.blogspot.com/2013/05/android-connecting-to-server-mysql.html
        ArrayList<NameValuePair> nameValuePairs =
                new ArrayList<NameValuePair>();
        try{
            HttpClient httpClient = new DefaultHttpClient();
            HttpPost httpPost =
                    new HttpPost("http://10.0.2.2/DBII_A2_v1/A3.php?table="
                            + edittext_text + "&attr=" + spinner_text);
            httpPost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
            HttpResponse response = httpClient.execute(httpPost);
            HttpEntity entity = response.getEntity();
            is = entity.getContent();
        } catch(Exception e){
            Log.e("log_tag", "Error in http connection" + e.toString());
        }

        try{
            BufferedReader reader =
                    new BufferedReader(new InputStreamReader(is,"iso-8859-1"),8);
            sb = new StringBuilder();
            sb.append(reader.readLine()+"\n");

            String line="0";
            while((line=reader.readLine()) !=null){
                sb.append(line+"\n");
            }
            is.close();
            result=sb.toString();
        } catch (Exception e){
            Log.e("log_tag","Error converting result"+e.toString());
        }

        String name;
        try{
            jArray = new JSONArray(result);
            JSONObject json_data = null;
            for(int i = 0; i<jArray.length();i++){
                json_data = jArray.getJSONObject(i);
                name = json_data.getString("NAME"); //???
            }
        } catch(JSONException e1){
            Toast.makeText(getBaseContext(),"No Data Found", Toast.LENGTH_LONG).show();
        }
        //catch(ParseException e1){
          //  e1.printStackTrace();
        //}
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void addListenerOnSpinnerItemSelection(){
        spinner1 = (Spinner) findViewById(R.id.search_table);
        spinner1.setOnItemSelectedListener(new MyOnItemSelectedListener());
    }

    public void urlGetter(){
        Spinner tableSpinner = (Spinner) findViewById(R.id.search_table);
        EditText nameText = (EditText) findViewById(R.id.search_for);

        String spinner_text = tableSpinner.getSelectedItem().toString();
        String edittext_text = nameText.getText().toString();


    }

}
