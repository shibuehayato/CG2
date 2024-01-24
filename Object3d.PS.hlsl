#include "object3d.hlsli"

struct Material {
    float32_t4 color;
	int32_t enableLighting;
	float32_t shininess;
};
ConstantBuffer<Material> gMaterial : register(b0);
Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct PixelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

struct DirectionalLight {
    float32_t4 color;
	float32_t3 direction;
	float intensity;
};

ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);

ConstantBuffer<Camera> gCamera : register(b2);

PixelShaderOutput main(VertexShaderOutput input) {
	PixelShaderOutput output;
	float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);

	if(gMaterial.enableLighting != 0){
       float Ndotl = dot(normalize(input.normal), normalize(-gDirectionalLight.direction));
	   float cos = pow(Ndotl * 0.5f + 0.5f, 2.0f);
	   output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;

	   float32_t3 toEye = normalize(gCamera.worldPosition - input.worldPosition);
	   float32_t3 reflectLight = reflect(gDirectionalLight.direction, normalize(input.normal));
	   float RdotE = dot(reflectLight , toEye);
	   float specularPow = pow(saturate(RdotE), gMaterial.shininess); // 反射強度

	   // 拡散反射
	   float32_t3 diffuse = 
	   gMaterial.color.rgb * textureColor.rgb * gDirectionalLight.color.rgb * cos * gDirectionalLight.intensity;
	   // 鏡面反射
	   float32_t3 specular = 
	   gDirectionalLight.color.rgb * gDirectionalLight.intensity * specularPow * float32_t3(1.0f, 1.0f, 1.0f);
	   // 拡散反射+鏡面反射
	   output.color.rgb = diffuse + specular;
	   // アルファは今まで通り
	   output.color.a = gMaterial.color.a * textureColor.a;

	} else {
	    output.color = gMaterial.color * textureColor;   
	}
	output.color.a = 1.0f;
	return output;
}
