//#version 330 core

//in vec3 vertexPosition;
//in vec2 vertexUV; 


//out vec2 uv;

//uniform mat4 projection_matrix;
//uniform mat4 view_matrix;
//uniform mat4 model_matrix; 



//void main(void)
//{
	//uv = vertexUV;
	//gl_Position = porjection_matrix * view_matrix * model_matrix *vec4(vertexPosition, 1);
//}

//#version 330 core
//layout (location = 0) in vec3 position; 
//void main()
//{
	//gl_Position = vec4(position.x, position.y, position.z, 1.0);
//}

//#version 130
//in vec3 vertexPosition;
//in vec2 vertexUV;

//out vec2 uv;

//uniform mat4 projection_matrix;
//uniform mat4 view_matrix;
//uniform mat4 model_matrix;

//void main(void)
//{
	//uv = vertexUV;
	//gl_Position = projection_matrix * view_matrix * model_matrix * vec4(vertexPosition, 1);


//}


//#version 330
//attribute vec3 position;
//attribute vec2 texCoord;

//void (main)
//{
	//gl_Position = vec4(position, 1.0);

//}


#version 150
in vec3 vert;
in vec2 positions
out vec2 texCoord

void main() {
    // Pass the tex coord straight through to the fragment shader
    texCoord= positions
    
    gl_Position = vec4(vert, 1);
}