package com.example.a230328

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import com.example.a230328.databinding.ActivityMainBinding

class MainBinding : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.getRoot())


        binding.button.setOnClickListener {
            if(binding.editText.text.toString() == "12345") {
                Toast.makeText(this, "valid", Toast.LENGTH_SHORT).show()
            }else {
                Toast.makeText(this, "invalid", Toast.LENGTH_SHORT).show()
            }
        }
    }
}