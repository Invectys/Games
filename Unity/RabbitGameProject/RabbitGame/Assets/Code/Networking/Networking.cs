using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class Networking : MonoBehaviour
{

    public string ServerUrl = "http://127.0.0.1:5000/";

    private void Awake()
    {
        
    }

    void Start()
    {

        StartCoroutine(GetWebInfo());
    }

    void Update()
    {
        
    }

    IEnumerator GetWebInfo()
    {
        UnityWebRequest www = UnityWebRequest.Get(ServerUrl);
        yield return www.SendWebRequest();

        if(www.isNetworkError || www.isHttpError)
        {
            Debug.Log(www.error);
        }
        else
        {
            var data = www.downloadHandler.data;
            string msg = System.Text.Encoding.ASCII.GetString(data);
            Debug.Log(msg);
        }
    }
}
