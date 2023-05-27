using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemies_PEDESTRIANS : MonoBehaviour
{
    // Types of pedestrians
    public enum EnemyTypes {
        OldMan,
        ScaterDude,
        GenZee,
        Exec
    }

    Rigidbody2D rb_Enemy;
    Transform player;

    [Header("Pedestrian Type")]
    public EnemyTypes enemyType;
    
    // Start is called before the first frame update
    void Start()
    {
        rb_Enemy = gameObject.GetComponent<Rigidbody2D>();

        player = GameObject.FindGameObjectWithTag("Player").transform;
    }

    // Update is called once per frame
    void Update()
    {
    }

    private void OnCollisionEnter2D(Collision2D collision) {
        if(collision.gameObject.CompareTag("Player")) {
            // Player will fall
        }
    }
}
