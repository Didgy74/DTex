#pragma once

namespace DTex
{
	enum class Format : uint32_t;
	enum class Target : uint32_t;

	class TextureDocument;
	using TexDoc = TextureDocument;
}

enum class DTex::Target : uint32_t
{
	Invalid,
	Texture1D,
	Texture2D,
	Texture3D,
};

enum class DTex::Format : uint32_t
{
	Invalid,

	// Standard
	R8G8B8_UNorm,
	R8G8B8A8_UNorm,

	// BCn
	BC1_RGB_UNorm,
	BC1_RGB_sRGB,
	BC1_RGBA_UNorm,
	BC1_RGBA_sRGB,
	BC2_UNorm,
	BC2_sRGB,
	BC3_UNorm,
	BC3_sRGB,
	BC4_UNorm,
	BC4_SNorm,
	BC5_UNorm,
	BC5_SNorm,
	BC6H_UFloat,
	BC6H_SFloat,
	BC7_RGBA_Unorm,
	BC7_sRGB_Unorm,
};