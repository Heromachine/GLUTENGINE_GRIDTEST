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

#version 330

varying vec2 texCoord0;

uniform sampler2D diffuse;

void main()
{
	gl_FragColor = texture2D(diffuse, texCoord0);

}
