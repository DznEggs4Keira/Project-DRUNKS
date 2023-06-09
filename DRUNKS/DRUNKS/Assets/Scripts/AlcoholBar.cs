using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AlcoholBar : MonoBehaviour
{
    public PlayerMovement alcohol;
    public float barValue;

    public Image alcoholBar;

    void Update()
    {
        barValue = alcohol.barValue;

        barValue = Mathf.Clamp(barValue, 0, 100);

        alcoholBar.fillAmount = barValue / 100;
    }
}
