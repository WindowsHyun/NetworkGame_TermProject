#include "main.h"

HWND hwndOwner;
RECT rc, rcDlg, rcOwner;
HWND ipAddr, CharName;
char ipAddres[MAX_PATH] = "127.0.0.1";
char nickName[16] = "Nothing";
bool GamePlayWait = true;

BOOL CALLBACK DlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
	switch ( uMsg ) {
	case WM_INITDIALOG:
		//-------------------------------------------------------------------------------------------------------------------------------------
		// 다이얼로그 박스를 중앙으로
		if ( (hwndOwner = GetParent( hDlg )) == NULL )
			hwndOwner = GetDesktopWindow();

		GetWindowRect( hwndOwner, &rcOwner );
		GetWindowRect( hDlg, &rcDlg );
		CopyRect( &rc, &rcOwner );

		OffsetRect( &rcDlg, -rcDlg.left, -rcDlg.top );
		OffsetRect( &rc, -rc.left, -rc.top );
		OffsetRect( &rc, -rcDlg.right, -rcDlg.bottom );

		SetWindowPos( hDlg, HWND_TOP, rcOwner.left + (rc.right / 2), rcOwner.top + (rc.bottom / 2), 0, 0, SWP_NOSIZE );
		//-------------------------------------------------------------------------------------------------------------------------------------
		//닉네임 중복 못하게 만들자
		char buf[10];
		srand( (unsigned)time( NULL ) );
		sprintf( buf, "%d", rand() % 10000 );
		strcat( nickName, buf );
		//-------------------------------------------------------------------------------------------------------------------------------------
		ipAddr = GetDlgItem( hDlg, IDC_EDIT1 );
		CharName = GetDlgItem( hDlg, IDC_EDIT2 );

		SetDlgItemText( hDlg, IDC_EDIT1, ipAddres );
		SetDlgItemText( hDlg, IDC_EDIT2, nickName );
		return TRUE;

	case WM_COMMAND:

		switch ( LOWORD( wParam ) ) {
		case IDC_BUTTON1:
			GetWindowText( ipAddr, ipAddres, MAX_PATH );
			GetWindowText( CharName, nickName, MAX_PATH );
			GamePlayWait = false;
			EndDialog( hDlg, IDCANCEL );
			return TRUE;

		case IDCANCEL:
			MessageBox( NULL, "연결을 하셔야 종료를 할 수 있습니다..!", "", 0 );
			return TRUE;

		}
		return FALSE;
	}
	return FALSE;
}