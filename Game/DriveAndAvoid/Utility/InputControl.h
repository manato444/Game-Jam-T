#pragma once

#include"Vector2D.h"

//���͊Ǘ��@�\
class InputControl
{
private:

	static bool now_button[16];		//���݃t���[�����͒l
	static bool old_button[16];		//�ߋ��t���[�����͒l
	static float trigger[2];		//���E�g���K�[���͒l
	static Vector2D stick[2];		//���E�X�e�B�b�N���͒l

	static float stick1[2];

public:

	//�X�V����
	static void Update(); 

	//�{�^�����͎擾����
	static bool GetButton(int button);		//���������Ă����
	static bool GetButtonDown(int button);	//�������u��
	static bool GetButtonUp(int button);	//�������u��

	//�g���K�[���͎擾����
	static float GetLeftTrigger();			//���g���K�[
	static float GetRightTrigger();			//�E�g���K�[

	//�X�e�B�b�N���͎擾����
	static Vector2D GetLeftStick();			//���X�e�B�b�N
	static Vector2D GetRightStick();		//�E�X�e�B�b�N

	//���X�e�B�b�N���͎擾�iX, Y�j
	static float GetLeft_Stick_X();
	static float GetLeft_Stick_Y();
	
	//static float SetLeft_Stick();

private:

	//�{�^���z��͈̓`�F�b�N
	static bool CheckButtonRange(int button);
};