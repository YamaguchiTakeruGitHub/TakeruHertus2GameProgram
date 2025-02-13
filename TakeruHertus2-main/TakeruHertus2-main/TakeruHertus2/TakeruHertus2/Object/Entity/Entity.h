#pragma once
#include "../Component/Base/Component.h"
#include "../Component/Base/ComponentCommon.h"

/// <summary>
/// ���ׂẴI�u�W�F�N�g�𒇉��N���X(�ʖ�Acter)
/// </summary>
class Entity
{
private:
	//�}�b�v�Ŗ��O�ƃ|�C���^���w��ł���悤�ɂ����R���|�[�l���g
	std::unordered_map<std::string, std::shared_ptr<Component>> components;

protected:
	
	/// <summary>
	/// �R���|�[�l���g�𐶐�����
	/// </summary>
	/// <typeparam name="T">�C�ӂ̃N���X</typeparam>
	/// <typeparam name="...Args">0�ȏ�̉σp�����[�^</typeparam>
	/// <param name="..._args">�C�ӂ̈���</param>
	template<typename T, typename... Args>
	void AddComponent(Args&&... _args)
	{
		components[typeid(T).name()] = std::make_shared<T>(std::forward<Args>(_args)...);
	}

	/// <summary>
	/// �R���|�[�l���g���擾����
	/// </summary>
	/// <typeparam name="T">�C�ӂ̃N���X</typeparam>
	/// <returns>���������R���|�[�l���g�ւ̃C���X�^���X��</returns>
	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		//�C�e���[�^�[
		auto it = components.find(typeid(T).name());
		if (it != components.end())
		{
			return std::dynamic_pointer_cast<T>(it->second);
		}
		return nullptr;
	}

	/// <summary>
	/// �R���|�[�l���g�̏�����
	/// </summary>
	void InitComponent();

	/// <summary>
	/// �R���|�[�l���g�̍X�V
	/// </summary>
	void UpdateComponent();
	
	/// <summary>
	/// �R���|�[�l���g�̕`��
	/// </summary>
	void DrawComponent();
	
	/// <summary>
	/// �R���|�[�l���g�̉��
	/// </summary>
	void FinalComponent();
	

};
