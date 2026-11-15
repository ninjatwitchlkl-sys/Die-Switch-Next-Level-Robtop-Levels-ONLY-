#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// When you die, wait a moment, then jump to the next official level.
// Official levels are IDs 1 to 22 (Stereo Madness to Fingerdash).
// Any other level (online or custom) sends you to Stereo Madness.

class $modify(DieSkipLayer, PlayLayer) {
	struct Fields {
		bool skipping = false;
		int nextId = 1;
	};

	void destroyPlayer(PlayerObject* player, GameObject* object) {
		PlayLayer::destroyPlayer(player, object);

		// Ignore the anti-cheat spike and editor playtests.
		if (object == m_anticheatSpike) return;
		if (m_level->m_levelType == GJLevelType::Editor) return;
		if (m_fields->skipping) return;

		m_fields->skipping = true;

		int id = m_level->m_levelID.value();
		m_fields->nextId = (id >= 1 && id <= 22) ? (id % 22) + 1 : 1;

		this->runAction(CCSequence::create(
			CCDelayTime::create(1.0f),
			CCCallFunc::create(this, callfunc_selector(DieSkipLayer::queueSkip)),
			nullptr
		));
	}

	// Don't swap scenes from inside this layer's own action.
	// Hand the work to the main thread and do it on the next frame instead.
	void queueSkip() {
		int next = m_fields->nextId;

		queueInMainThread([next]() {
			auto level = LevelTools::getLevel(next, false);
			if (!level) return;

			auto scene = PlayLayer::scene(level, false, false);
			if (!scene) return;

			CCDirector::get()->replaceScene(CCTransitionFade::create(0.5f, scene));
		});
	}
};
