#include "Light.h"


Light::Light(DirectX::SimpleMath::Color _col, float _intensity)
{
	m_Color = _col;
	m_Intensity = _intensity;
}

DirectX::SimpleMath::Color Light::GetColor()
{
	return m_Color * m_Intensity;
}

Light::~Light(void)
{
}
