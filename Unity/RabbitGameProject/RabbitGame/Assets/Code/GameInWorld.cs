using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameInWorld : MonoBehaviour
{

    public Animal PlayerAnimalPrefab;
    public CameraMovement PlayerCamera;

    Game _game;

    private void Awake()
    {
        _game = Game.GetInstance();
        _game.SetPlayerAnimalPrefab(PlayerAnimalPrefab);
        _game.SetCamera(PlayerCamera);
    }

    void Start()
    {
        _game.StartGame();
    }

    void Update()
    {
        
    }
}
