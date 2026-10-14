#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(AICreatorLayer, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("AI"),
            this,
            menu_selector(AICreatorLayer::onAICreator)
        );

        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition({winSize.width - 40.f, 40.f});
        menu->setID("ai-creator-menu"_spr);
        this->addChild(menu);

        return true;
    }

    void onAICreator(CCObject*) {
        FLAlertLayer::create(
            "AI Creator",
            "Giai doan 1 hoat dong. Chat AI se duoc them o giai doan 2.",
            "OK"
        )->show();
    }
};
