using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemies_STATIC : MonoBehaviour
{
    // Types of static enemies
    public enum EnemyTypes {
        TrafficCones,
        FloorHoles
    }

    protected bool isPickable;
    Rigidbody2D rb_Enemy;
    Transform player;

    [Header("Enemy Type")]
    public EnemyTypes enemyType;
    
    // Start is called before the first frame update
    void Start()
    {
        if(enemyType == 0) {
            isPickable = true;
        } else {
            isPickable = false;
        }

        rb_Enemy = gameObject.GetComponent<Rigidbody2D>();

        player = GameObject.FindGameObjectWithTag("Player").transform;
    }

    // Update is called once per frame
    void Update()
    {
        // TODO - Probably goes into the player script.
        // if the player interacts with it - RIGHT MOUSE DOWN
        if (Input.GetButtonDown("Fire2")) {
            if (isPickable) {
                // the cone is thrown away in the direction of the player.
                // Use Raycast to precisely select a traffic cone
                if (rb_Enemy != null) {
                    rb_Enemy.AddForce(player.right);
                }
            }
        }
    }

    private void OnCollisionEnter2D(Collision2D collision) {
        if(collision.gameObject.CompareTag("Player")) {
            // Player will fall
        }
    }
}
