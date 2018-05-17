//#version 330

//uniform sampler2D texture; 
//in vec2 uv;
//out vec4 fragment;



//void main()
//{
	//fragment = texture2D(texture, uv); 
//}

//#version 120


//void main()
//{
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
//}

//#version 130

//uniform sampler2D texture;
//in vec2 uv;

//out vec4 fragment;

//void main(void)
//{
  //fragment = texture2D(texture, uv);
//}

//#version 120

//varying vec2 texCoord0;

//uniform sampler2D diffuse;

//void main()
//{
	//gl_FragColor = texture2D(diffuse, texCoord0);

//}


#version 150
uniform sampler2D tex; //this is the texture
in vec2 texCoord//this is the texture coord
out vec4 finalColor; //this is the output color of the pixel

void main() {
    finalColor = texture(tex, fragTexCoord);
}
