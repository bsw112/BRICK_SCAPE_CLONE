#pragma once
#include "GameObject.h"


#include "Management.h"
#include "Client_Defines.h"


BEGIN(Client)

class CWall : public CGameObject
{
public:
	typedef struct tagStatedesc
	{
		BASEDESC tBaseDesc;

	}STATEDESC;
protected:
	explicit CWall(PDIRECT3DDEVICE9 pGraphic_Device);
	explicit CWall(const CWall& rhs);
	virtual ~CWall() = default;


public:
	virtual HRESULT Ready_GameObject_Prototype();
	virtual HRESULT Ready_GameObject(void* pArg);
	virtual _int Update_GameObject(_double TimeDelta);
	virtual _int Late_Update_GameObject(_double TimeDelta);
	virtual HRESULT Render_GameObject();

private:
	CTransform*	m_pTransform = nullptr;
	CVIBuffer*	m_pVIBuffer = nullptr;
	CTexture*	m_pTexture = nullptr;
	CRenderer*	m_pRenderer = nullptr;
	CShader*	m_pShader = nullptr;

private:
	STATEDESC	m_tDesc;
public:
	static CWall* Create(PDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone_GameObject(void* pArg);
	virtual void Free();


};
END
