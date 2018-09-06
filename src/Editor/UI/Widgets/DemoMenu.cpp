#include "DemoMenu.h"
#include "Screen.h"
#include "demo.h"
#define NewDemo(X) 	if (currentDemo != nullptr)\
	{\
	Global<Context>().GetSubsystem<Screen>()->m_testDemos.pop_back();\
	delete currentDemo;\
	}\
	currentDemo = new X();\
	Global<Context>().GetSubsystem<Screen>()->m_testDemos.push_back(currentDemo);\
    currentDemo->Initlization();

    //Global<Context>().GetSubsystem<Screen>()->CreateFrameBufer(); \

#define ShowDemo(X) void show##X ()\
						{ NewDemo(x); }

typedef void(*SimpleFunc)();

struct EntryPoint
{
	const char * name;
	SimpleFunc  fun;
};

EntryPoint * entry;
DemoTest *currentDemo;

void showDemo1()
{
	NewDemo(DemoBox2d);
}

void showDemo2()
{
	NewDemo(DemoTriangle);
}
void showDemo3()
{
    NewDemo(DemoModel);
}

EntryPoint g_testEntries[]
{
	{"Box2d",showDemo1},
     {"Avatar",showDemo3},
	{"Triangle",showDemo2}
   
};

static bool sTestEntriesGetName(void*, int idx, const char** out_name)
{
	*out_name = g_testEntries[idx].name;
	return true;
}

void TmingEngine::DemoMenu::Begin()
{

}

void TmingEngine::DemoMenu::Update()
{
	bool p_open = true;
	//ImGui::SetNextWindowPos(ImVec2(200, 10));
	ImGui::SetNextWindowSize(ImVec2(200, 560), ImGuiCond_FirstUseEver);
	if (!ImGui::Begin("DemoMenu", &p_open))
	{
		ImGui::End();
		return;
	}

	ImGui::PushAllowKeyboardFocus(false); // Disable TAB

	ImGui::PushItemWidth(-1.0f);

	ImGui::Text("Test");
	if (ImGui::Combo("##Test", &testIndex, sTestEntriesGetName, NULL, testCount, testCount))
	{
		entry = g_testEntries + testIndex;
		entry->fun();
		testSelection = testIndex;
	}
	ImGui::Separator();

	ImGui::Text("Vel Iters");
	ImGui::PopAllowKeyboardFocus();
	ImGui::End();
}

void TmingEngine::DemoMenu::End()
{
}
