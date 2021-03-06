#pragma once

#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CComponent abstract : public CBase
{
protected:
	explicit CComponent(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CComponent(const CComponent& rhs);
	virtual ~CComponent() = default;
public:
	virtual HRESULT Ready_Component_Prototype();
	virtual HRESULT Ready_Component(void* pArg);
public:
	void	Set_Enable(_bool _bEnable) { m_bEnable = _bEnable; }

protected:
	LPDIRECT3DDEVICE9		m_pGraphic_Device = nullptr;
	_bool					m_isClone = false;
	_bool					m_bEnable = true;


public:
	virtual CComponent* Clone_Component(void* pArg) = 0;
	virtual void Free();
};

END