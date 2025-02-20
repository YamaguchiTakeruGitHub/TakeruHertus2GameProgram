// ピクセルシェーダーの入力
struct PS_INPUT
{
    float4 dif : COLOR0; // ディフューズカラー
    float2 texCoords0 : TEXCOORD0; // テクスチャ座標
};

// ピクセルシェーダーの出力
struct PS_OUTPUT
{
    float4 color0 : SV_TARGET0; // 色
};


// 定数バッファピクセルシェーダー基本パラメータ
struct DX_D3D11_PS_CONST_BUFFER_BASE
{
    float4 FactorColor; // アルファ値等

    float MulAlphaColor; // カラーにアルファ値を乗算するかどうか( 0.0f:乗算しない  1.0f:乗算する )
    float AlphaTestRef; // アルファテストで使用する比較値
    float2 Padding1;

    int AlphaTestCmpMode; // アルファテスト比較モード( DX_CMP_NEVER など )
    int3 Padding2;

    float4 IgnoreTextureColor; // テクスチャカラー無視処理用カラー
};

// 基本パラメータ
cbuffer cbD3D11_CONST_BUFFER_PS_BASE : register(b1)
{
    DX_D3D11_PS_CONST_BUFFER_BASE g_Base;
};


SamplerState g_DiffuseMapSampler : register(s0); // ディフューズマップサンプラ
Texture2D g_DiffuseMapTexture : register(t0); // ディフューズマップテクスチャ


float3 AdjustHue(float3 color, float hueAdjust)
{
    float angle = hueAdjust * 3.14159265 / 180.0;
    float s = sin(angle);
    float c = cos(angle);

    float3x3 hueRotation = float3x3(
        0.299 + 0.701 * c + 0.168 * s, 0.587 - 0.587 * c + 0.330 * s, 0.114 - 0.114 * c - 0.497 * s,
        0.299 - 0.299 * c - 0.328 * s, 0.587 + 0.413 * c + 0.035 * s, 0.114 - 0.114 * c + 0.292 * s,
        0.299 - 0.300 * c + 1.250 * s, 0.587 - 0.588 * c - 1.050 * s, 0.114 + 0.886 * c - 0.203 * s
    );

    return mul(color, hueRotation);
}


// main関数
PS_OUTPUT main(PS_INPUT PSInput)
{
    PS_OUTPUT PSOutput;
    float4 TextureDiffuseColor;

	// テクスチャカラーの読み込み
    TextureDiffuseColor = g_DiffuseMapTexture.Sample(g_DiffuseMapSampler, PSInput.texCoords0);
	
	// 出力カラー = テクスチャカラー * ディフューズカラー
    PSOutput.color0 = TextureDiffuseColor * PSInput.dif;
	
	// 出力パラメータを返す
    return PSOutput;
}

