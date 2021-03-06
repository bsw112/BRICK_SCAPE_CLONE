#include "..\Headers\Scene_Manager.h"

IMPLEMENT_SINGLETON(CScene_Manager)

CScene_Manager::CScene_Manager()
{

}

HRESULT CScene_Manager::SetUp_CurrentScene(CScene * pCurrentScene, _uint _iSceneID)
{
	Safe_Release(m_pCurrentScene);

	m_pCurrentScene = pCurrentScene;
	m_iCurrScene = _iSceneID;

	return S_OK;
}

_int CScene_Manager::Update_CurrentScene(_double TimeDelta)
{
	if (nullptr == m_pCurrentScene)
		return -1;

	return m_pCurrentScene->Update_Scene(TimeDelta);	
}

HRESULT CScene_Manager::Render_CurrentScene()
{
	if (nullptr == m_pCurrentScene)
		return E_FAIL;

	if (FAILED(m_pCurrentScene->Render_Scene()))
		return E_FAIL;

	return S_OK;
}

_uint CScene_Manager::Get_CurrScene()
{
	return m_iCurrScene;
}

void CScene_Manager::Free()
{
	Safe_Release(m_pCurrentScene);
}
