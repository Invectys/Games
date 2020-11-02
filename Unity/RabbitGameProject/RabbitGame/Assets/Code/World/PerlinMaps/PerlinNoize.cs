using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PerlinNoize : MonoBehaviour
{
    public Texture2D NoizeMap 
    { 
        get 
        { 
            return _texture; 
        } 
    }

    [Header("For Tests")]
    public Renderer Renderer;

    [Header("Settings")]
    public float Scale = 20;
    public int OffsetX = 0;
    public int OffsetZ = 0;
    public int Width = 256;
    public int Heigth = 256;

    private Texture2D _texture;

    void Awake()
    {
        Debug.Log("Noize was generated");
        _texture = GeneratePerlinMap();
        if (Renderer != null) Renderer.material.mainTexture = _texture;
    }

    void Start()
    {
    }


    void Update()
    {
        _texture = GeneratePerlinMap();
        if (Renderer != null) Renderer.material.mainTexture = _texture;

    }

   

    Texture2D GeneratePerlinMap()
    {
        Texture2D texture = new Texture2D(Width, Heigth);
        for (int x = 0; x <= Width; x++)
        {
            for (int z = 0; z <= Heigth; z++)
            {
                Color color = getColor(x, z);
                texture.SetPixel(x, z, color);
            }
        }

        texture.Apply();
        return texture;
    }

    Color getColor(int x, int z)
    {
        float xPerlinCoords = (float)x / Width * Scale + OffsetX;
        float zPerlinCoords = (float)z / Heigth * Scale + OffsetZ;

        float perlinVal = Mathf.PerlinNoise(xPerlinCoords, zPerlinCoords);
        Color color = new Color(perlinVal, perlinVal, perlinVal);
        return color;
    }
}
