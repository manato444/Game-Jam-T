#include"TitleScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"



TitleScene::TitleScene() : background_image(NULL), menu_image(NULL), sound(NULL),
						   cursor_image(NULL), menu_cursor(0)
{
}

TitleScene::~TitleScene()
{
}

//����������
void TitleScene::Initialize()
{

	
	//�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/Title.bmp");
	//background_image = LoadGraph("Resource/images/End.bmp");

	menu_image = LoadGraph("Resource/images/menu.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");

	//���ʉ�
	sound = LoadSoundMem("Resource/sound/engine.mp3");

	GraphFilter(menu_image, DX_GRAPH_FILTER_HSB, 0, 1, 0, 0);
	GraphFilter(background_image, DX_GRAPH_FILTER_LEVEL, 30, 210, 120, 0, 255);

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmp������܂���\n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/menu.bmp������܂���\n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmp������܂���\n");
	}
	
}

//�X�V����
eSceneType TitleScene::Update()
{
	bool flg = TRUE;
	//�J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN) || CheckHitKey(KEY_INPUT_DOWN) > 0)
	{
		if (flg == TRUE)
		{
			menu_cursor++;
		}
		else
		{
			flg = TRUE;
		}
		flg = FALSE;
		//1�ԉ��ɓ��B������A��ԏ�ɂ���
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
		
	}

	//�J�[�\����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP) || CheckHitKey(KEY_INPUT_UP) > 0)
	{
		menu_cursor--;
		//1�ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}

	//�J�[�\������(���肵����ʂɑJ�ڂ���)
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B) || CheckHitKey(KEY_INPUT_RETURN))
	{
		PlaySoundMem(sound, TRUE);
		
		switch (menu_cursor) 
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RANKING_DISP;
		case 2:
			return eSceneType::E_HELP;
		default:
			return eSceneType::E_END;
		}
	}

	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();

}

//�`�揈��
void TitleScene::Draw() const
{
	//���j���[�`�J�`�J�`
	GraphFilter(menu_image, DX_GRAPH_FILTER_HSB, 0, 2, 3, 5);

	//�^�C�g���摜�̕`��
	DrawGraph(0, 0, background_image, FALSE);

	//���j���[�摜�̕`��
	DrawGraph(120, 200, menu_image, TRUE);

	//�J�[�\���摜�̕`��
	DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image, TRUE);

	//DrawGraph(20, 300, menu_image, TRUE);
	//DrawRotaGraph(250, 320 + menu_cursor * 40, 0.7, DX_PI / -2.0, cursor_image, TRUE);

	//DrawString(8, 460, "B:����", 0xffffff, 0);
}

//�I��������
void TitleScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

//���݂̃V�[�������擾
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}